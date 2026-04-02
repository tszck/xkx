// /cmds/usr/help.c
inherit F_CLEAN_UP;

#include "/doc/help.h";
#include "ansi.h";


string *default_search = DEFAULT_SEARCH_PATHS;
string skill_level(string, int);
string skill_enables(object sk);
int sort_skill(string file);
mapping valid_type = ([
        "array":        "陣法",
        "axe":          "斧法",
        "blade":        "刀法",
        "claw":         "爪法",
        "club" :        "棍法",
        "cuff":         "拳法",
        "dagger":       "短兵",
        "dodge":        "輕功",
        "finger":       "指法",
        "force":        "內功",
        "hammer":       "錘法",
        "hand":         "手法",
        "hook":         "鈎法",
        "leg":          "腿法",
        "magic":        "法術",
        "parry":        "招架",
        "spear":        "槍法",
        "staff":        "杖法",
        "stick":        "棒法",
        "strike":       "掌法",
        "sword":        "劍法",
        "throwing":     "暗器",
        "unarmed":      "拳腳",
        "whip":         "鞭法",
]);


int main(object me, string arg)
{
	int i, j = 0, k, w, templen;
	string file, *search, exert, str, *skfile, here, here1;
	object sk;
	mapping lrn;
	mixed *cmds;

// 不帶參數，則顯示幫助主菜單
	if( !arg )
	{
//		cat(HELP_DIR + "help/topics");
		me->start_more(read_file(HELP_DIR + "help/topics"));
		return 1;
	}
// 參數為here，顯示本地所在地址的幫助
	if( arg == "here")
	{
		file = file_name(environment(me));
		if( sscanf(file, "/d/%s/%s", here, here1) != 2)
			return notify_fail("這個地方沒有幫助説明。\n");
		else
		{
// 揚州目錄為city，特別列出
			if( here == "city") arg = "yangzhou";
			else arg = here;
		}
	}
// 命令幫助，則取 /cmds/目錄下的命令文件的自帶幫助
	if( arg == "cmds")
	{
		cmds = get_dir("/cmds/usr/");
		write(HIC"〖用戶系統命令〗\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
		  if ( file[strwidth(file)-2..strwidth(file)-1]==".c" &&
//			if(strsrch(file,".c") >= 0 &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strwidth(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		cmds = get_dir("/cmds/std/");
		write(HIC"〖交流探險命令〗\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
//			if(strsrch(file,".c") >= 0 &&
		  if ( file[strwidth(file)-2..strwidth(file)-1]==".c" &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strwidth(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		cmds = get_dir("/cmds/skill/");
		write(HIC"〖武功技能命令〗\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
//			if(strsrch(file,".c") >= 0 &&
		  if ( file[strwidth(file)-2..strwidth(file)-1]==".c" &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strwidth(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		write(HIY"請用help <命令名> 查看詳細説明。\n"NOR);
		return 1;
	}
// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) )
	{
		notify_fail("有這個指令存在，但是並沒有詳細的説明文件。\n");
		return file->help(me);
	}

// 查找幫助文件的路徑
	if( pointerp(search = me->query("help_search_path")) )
	{
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 )
		{
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

// Support efun/lfun help with same name as other topics such as
// ed() and ed command.
	sscanf(arg, "%s()", arg);

// Finally, search the default search paths.
	if( pointerp(default_search) )
	{
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 )
		{
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
	}
// 武功幫助文件
	sscanf(arg, "%s.%s", arg, str);
	if(file_size(SKILL_D(arg)+".c") < 1)
		return notify_fail("沒有針對這項主題的説明文件。\n");

// 武功絕招幫助文件
	if( stringp(str) )
	{
		if( stringp(exert = SKILL_D(arg)->exert_function_file("")) &&
			file_size(exert + str +".c") > 0)
		{
			notify_fail("對不起，"+to_chinese(arg)+"內功方面的「"+str+"」功能沒有詳細的説明。\n");
			return (exert + str)->help(me);
		}
		else
		if( stringp(exert = SKILL_D(arg)->perform_action_file("")) &&
			file_size(exert + str +".c") > 0)
		{
			notify_fail("對不起，"+to_chinese(arg)+"外功方面的「"+str+"」功能沒有詳細的説明。\n");
			return (exert + str)->help(me);
		}
		return notify_fail("對不起，"+to_chinese(arg)+"沒有「"+str+"」這項功能。\n");
	}
	if(!SKILL_D(arg)->help(me))
	{
		write(HIY"\n指定武技沒有詳細幫助説明。\n"NOR);
	}

	lrn = me->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	str = sprintf("\n┌--------%s",HIW"【"YEL+to_chinese(arg)+HIW"    功能表】"NOR);
	str += sprintf("----------------------");
	for (k=18-strwidth(to_chinese(arg)); k>0; k--)
	{
		str += sprintf("--");
		k--;
	}
	str += sprintf("┐\n");

	str = replace_string(str, "  ", "--");
//	str += sprintf("│"HIY"目前等級"NOR"：     %3d/%6d              "HIY "武功類別"NOR"：  %-4s%9s\n", me->query_skill(arg, 1), (int)lrn[arg], SKILL_D(arg)->type()=="knowledge" ? "知識":"武技", "│");
	str += sprintf("│"HIY"目前等級"NOR"：     %3d/%6d              "HIY "武功類別"NOR"：  %-4s%9s\n", me->query_skill(arg, 1), (int)lrn[arg], SKILL_D(arg)->type()=="knowledge" ? "知識" : SKILL_D(arg)->martialtype()=="skill" ? "武技" : SKILL_D(arg)->martialtype()=="dodge" ? "輕功" : "內功" , "│");

	if(SKILL_D(arg)->type() != "martial" ||
		member_array(arg, keys(valid_type))!=-1)
		return notify_fail(str+"└--------------------------------------------------------------┘\n");
	str+="│                                                              │\n";
	sk = load_object(SKILL_D(arg));

	exert = skill_enables(sk);
	if(exert != "")
	{
		str += exert;
		i++;
	}

	if( stringp(exert = SKILL_D(arg)->exert_function_file("")) )
	{
		skfile = get_dir(exert);
		if( sizeof(skfile) > 0)
		{
			skfile = filter_array(skfile, (: sort_skill :) );
			j = sizeof(skfile);
		}
	}

	if(j && j > 0)
	{
		if( i ) str = str +"├--------------------------------------------------------------┤\n";
		str += "│"HIM"內功方面"NOR"：                                                    │\n";
		str += "│"HIC"(exert + )";
		for(i=0; i < j; i++){
			if (i % 4 == 0)
			{
				for (k = 52-templen; k >0; k--)
					str += " ";
				str += "│\n│          ";
				templen = 0;
			}
			str += sprintf("%-14s ",YEL+replace_string(skfile[i], ".c", "")+NOR);
			templen += strwidth(replace_string(skfile[i], ".c", "")) +1;
		}
		for (k = 52-templen; k >0; k--)
			str += " ";
		str += "│\n";
		j = 0;
	}

	if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
		skfile = get_dir(exert);
		if( sizeof(skfile) > 0){
			skfile = filter_array(skfile, (: sort_skill :) );
			j = sizeof(skfile);
		}
	}

	if(j && j > 0)
	{
		if( i )
			str = str +"├--------------------------------------------------------------┤\n";
		str += "│"HIY"外功方面"NOR"：                                                    │\n";
		str += "│"HIC"(perform+)"NOR;
		for(i=0; i < j; i++){
			if (i % 4 == 0)
			{
				for (k = 52-templen; k >0; k--)
					str += " ";
				str += "│\n│          ";
				templen = 0;
			}
			str += sprintf("%s ",WHT+replace_string(skfile[i], ".c", "")+NOR);
			templen += strwidth(replace_string(skfile[i], ".c", "")) +1;
		}
		for (k = 52-templen; k >0; k--)
			str += " ";
		str += "│\n";
	}
	str += "└--------------------------------------------------------------┘\n";
	write(str);
	return 1;
}

string skill_enables(object sk)
{
	int i, j, k, templen;
	string str, *skills;
	skills = keys(valid_type);

	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}

	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	str = "│"HIY"特殊技能"NOR"：                                                    │\n";
	str += "│"HIC"(enable+ )"NOR;
	templen = 0;
	for(i=0; i < j; i++) {
		if (i % 4 == 0)
		{
			for (k = 52-templen; k >0; k--)
				str += " ";
			str += "│\n│          ";
			templen = 0;
		}
		str += sprintf("%s ", valid_type[skills[i]]+"("+skills[i]+")");
		templen += strwidth(valid_type[skills[i]]+"("+skills[i]+")") + 1;
	}
	for (k = 52-templen; k >0; k--)
	{
		str += " ";
	}
	str += "│\n";
	return str;
}
int sort_skill(string file)
{
	int i;
  if (strwidth(file) < 2) return 0;
  if (file[strwidth(file)-2..strwidth(file)-1]!=".c") return 0;
//	if ( !sscanf(file, "%*s.c") ) return 0;
	i = strwidth(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( (file[i] < 'a' || file[i] > 'z' )
		    && (file[i] < '0' || file[i] > '9' )
		)
			return 0;
	}
	return 1;
}

int help(object me)
{
	write(@HELP

指令格式：help <主題>              例如：> help cmds
          help <武功名>            例如：> help force
          help <函數名稱>()        例如：> help call_out()
          help here                顯示所在地域的介紹

    這個指令提供你針對某一主題的詳細説明文件，若是不指定主題，
則提供你有關主題的文件。

HELP
	);
	return 1;
}
