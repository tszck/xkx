// Room: /d/huashan/lianhua.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "蓮花峯");
	set("long", @LONG
太華西峯又名蓮花峯，也叫芙蓉峯，峯頂有一塊巨石，狀如蓮花，
覆蓋崖巔。該處由此得名。這裏懸崖陡峭，壁立千仞，登臨遠眺，秦川
莽莽，渭、洛二水盤屈如帶。峯頂有石名“摘星石”，取“手可摘星辰”
之意，以狀西峯之高。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown" : __DIR__"chengxiang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");

	set("coor/x", -910);
	set("coor/y", 180);
	set("coor/z", 140);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/lianhua", 1);
	return;
}
