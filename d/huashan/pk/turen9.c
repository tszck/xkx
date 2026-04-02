// Room: /d/pk/turen9.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", MAG "紫竹林" NOR);
	set("long", @LONG
這裏就是華山捨身崖頂上的紫竹林了，放眼望去，四
周的翠竹攏罩在一層紫霧中，霧靄彌矇，身處其中，你才
能真正體會＂只在此山中，雲深不知處＂的妙境。每年的
華山論劍大會便在此竹林中舉行。
LONG
	);
	set("no_quit",1);
	set("bwdhpk",1);
	set("no_sleep_room",1);
	setup();
}
void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"turen"+random(7));
  me->set("exits/west",__DIR__"turen"+random(10));
  me->set("exits/northeast",__DIR__"turen"+random(9));
  me->set("exits/southwest",__DIR__"turen"+random(9));
}
