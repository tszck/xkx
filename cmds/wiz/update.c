// update.c
inherit F_CLEAN_UP;

#include "/doc/help.h"



int update_player(object me);
int updatefile(object me,string file) ;

int main(object me, string file)
{
	int i;
	object obj;
	// string err;
	mixed files;
	string dir;
	string* temp;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要重新編譯什麼檔案？\n");

	if( (obj = present(file, environment(me))) && interactive(obj) )
		return update_player(obj);

	if( file == "me" )
		return update_player(me);

  if (file[strwidth(file)-1]=='/')
	{
		file = file[0..strwidth(file)-2];
		dir = resolve_path(me->query("cwd"), file);
		dir += "/";
	}
  else
  {
  	dir = resolve_path(me->query("cwd"), file);
//  	write("adir= "+dir+"\n");
		if (file_size(dir) > 0) return updatefile(me,dir);
		else if (file_size(dir+".c") > 0) return updatefile(me,dir+".c");
//  	write("bdir= "+dir+"\n");
	}
	if( file_size(dir)==-2 && dir[strwidth(dir)-1] != '/' ) dir += "/";
//  	write("cdir= "+dir+"\n");
	files = get_dir(dir, -1);
	if( !sizeof(files) )
	{
		if (file_size(dir) == -2) return notify_fail("目錄是空的。\n");
		else return notify_fail("沒有這個文件或目錄。\n");
	}
	if (dir[sizeof(dir)-1]!='/')
	 {
	 	temp = explode(dir,"/");
	 	temp -= ({temp[sizeof(temp)-1]});
  	dir = implode(temp,"/");
  	dir += "/";
  }
	for (i=0;i<sizeof(files);i++)
	{
		file = files[i][0];
//		file = resolve_path(me->query("cwd"), file);
		file = dir + file;
//		write("file="+file+"\n");
//		if( !sscanf(file, "%*s.c") ) file += ".c";
    if (file[strwidth(file)-2..strwidth(file)-1] != ".c") file += ".c";
	  updatefile(me,file);
	}
	return 1;
}

int updatefile(object me,string file)
{
	object obj,*inv;
	int i;
	string err;
	me->set("cwf", file);

		if( file_size(file)==-1 )
			return notify_fail("沒有這個檔案。\n");
	if (obj = find_object(file))
	{
		if( obj==environment(me) )
		{
			if( file_name(obj)==VOID_OB )
				return notify_fail("你不能在 VOID_OB 裏重新編譯 VOID_OB。\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		}
		destruct(obj);
	}
	if (obj) return notify_fail("無法清除舊程式碼。\n");

	write("重新編譯 " + file + "：");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "發生錯誤：\n%s\n", err );
	else {
		write("成功！\n");
	}
	if( (i=sizeof(inv)) && (obj = find_object(file)))
	{
		while(i--)
		{
			if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
	return 1;
}
int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("身體更新完畢。\n\n");
	obj->move(env);
	obj->write_prompt();

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : update <檔名|here|me|玩家名>

這個指令可以更新檔案, 並將新檔的內容載入記憶體內. 若目標爲
'here' 則更新所在環境. 若目標爲 'me' 則更新自己的人物. 若目
標爲玩家則可更新玩家物件.

HELP
    );
    return 1;
}
