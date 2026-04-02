// config.c

inherit F_CLEAN_UP;

#include <runtime_config.h>


int main(object me, string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 ) {
		write("Mud 名稱：\t\t" + get_config(__MUD_NAME__) + "\n");
		write("網絡地址名稱服務器埠號：" + get_config(__MUD_IP__) + "\n");
		write("Mudlib 路徑：\t\t" + get_config(__MUD_LIB_DIR__) + "\n");
		write("MudOS 可執行文件路徑：\t" + get_config(__BIN_DIR__) + "\n");
		return 1;
	}

	printf("get_config(%d) = %O\n", num, get_config(num));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : config

顯示本泥潭的啓動配置。
HELP
     );
     return 1;
}
