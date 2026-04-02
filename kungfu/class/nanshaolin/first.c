#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("nanshaolin")+"/tianhong");
	set("start_room","/d/nanshaolin/dxshijie");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "男性" || ob->query("class") != "bonze")
	{
		return "本派掌門弟子歷來由出家和尚擔任！";
	}
	return ::zm_apply();
}