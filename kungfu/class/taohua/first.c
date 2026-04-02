#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("taohua")+"/huang");
	set("start_room","/d/taohua/dating");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") == "eunach" || ob->query("class") == "officer")
	{
		return "官場大內無恥之輩，豈能出任掌門弟子一職！";
	}	return ::zm_apply();
}