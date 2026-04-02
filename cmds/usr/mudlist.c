// mudlist.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>



#define	SYNTAX	"指令格式：mudlist [<Mud 名稱>]\n"

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("網路精靈並沒有被載入，請先將網路精靈載入。\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "目前並沒有跟網路上其他 Mud 取得聯繫。\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "並沒有和這個 Mud 取得聯繫。\n");
			return 1;
		}
		printf("有關 %s 的資訊：\n%O\n", arg, mud_list[arg]);
		return 1;
	}

	output = "ＭＵＤ名稱\t 中文名稱\t  網   址\t端口\t玩家數\n--------------------------------------------------------------\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-14s%-18s%6s\t%s\t%s\n", muds[loop],
			mud_list[muds[loop]]["MUDNAME"],
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			mud_list[muds[loop]]["USERS"] );
			this_player()->start_more( output );

	return 1;
}


int help(object me)
{
	write(@HELP
指令格式：mudlist [<泥巴名稱>]

    這個指令讓你列出目前跟這個 Mud 取得聯繫中的其他 Mud。
HELP
	);
	return 1;
}
