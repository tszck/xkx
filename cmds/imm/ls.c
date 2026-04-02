// ls.c

inherit F_CLEAN_UP;

#include "/doc/help.h"



int main(object me, string arg)
{
//	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strwidth(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{if (file_size(dir) == -2) return notify_fail("目錄是空的。\n");
		else
		return notify_fail("沒有這個目錄。\n");
	}

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strwidth(file[i][0])>w) w = strwidth(file[i][0]) + 1;
	}
	write("目錄：" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
			printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
				file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
				((i+1)%col)?"  ":"\n");
	else write("    沒有任何檔案。\n");
	write("\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: ls [<路徑名>]

列出目錄下所有的子目錄及檔案, 如果沒有指定目錄, 則列出所在目錄
的內容，所列出的檔案中前面標示 * 號的是已經載入的物件。

範例:
'ls /' 會列出所有位於根目錄下的檔案及子目錄.

HELP
	);
	return 1;
}