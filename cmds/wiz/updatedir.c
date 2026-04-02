// updatedir.c
inherit F_CLEAN_UP;

#include "/doc/help.h"


int updatefile(object me,string file);
int main(object me, string arg)
{
	int i, j;
	string dir;
	mixed *file;

	seteuid( geteuid(me) );

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strwidth(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{
		if (file_size(dir) == -2) return notify_fail("目錄是空的。\n");
		else return notify_fail("沒有這個目錄。\n");
	}
	i = sizeof(file);
	while(i--)
	{
		if (file[i][1]==-2) file[i][0] += "/";
	}
	write("目錄：" + dir + "\n");

	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
		{
		       	if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")
       				&& file[i][0][strwidth(file[i][0])-1]=="c"[0]
				&& file[i][0][strwidth(file[i][0])-2]=="."[0])
				updatefile(me,dir+file[i][0]);
			else
				if (file[i][1]==-2)
				call_other(__FILE__,"main", me,dir+file[i][0]);
		}
	else write("沒有任何檔案。\n");
	write("\n");

	return 1;
}

int updatefile(object me,string file)
{
	object obj,*inv;
	int i;
	string err;
	me->set("cwf", file);

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
}

int help(object me)
{
write(@HELP
指令格式: updatedir [<路徑名>]

將目錄下所有的子目錄及檔案, 如果沒有指定目錄, 則使用當前目錄。


範例:
'updatedir /adm' 會將所有位於根/adm目錄下的檔案編譯更新.

HELP
);
return 1;
}
