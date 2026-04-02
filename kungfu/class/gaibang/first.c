
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("gaibang")+"/hong");
	set("start_room", "/d/gaibang/pomiao");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if ( ob->query("party/party_name")!= HIC"丐幫"NOR )
	  return "非丐幫有袋弟子，不能勝任掌門弟子一職。";
	return ::zm_apply();
}
