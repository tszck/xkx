// Room: /d/lingxiao/iceroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰道");
	set("long",@LONG
這裏是凌霄城的南街，凌霄城的弟子、親人、家屬，盡皆居住在城
裏。凌霄城自創派以來一百餘年，歷代先祖皆是飽學逍遙之士，以老子
之黃庭為銘，避人間之煩囂，享高處之清寒，是以凌霄弟子居此西域冷
僻之地，仍能生生不息。這裏人來人往，西面是一家刀劍鋪，東邊是一
家藥鋪。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad1",
		"north" : __DIR__"iceroad3",
		"west"  : __DIR__"wuqi",
		"east"  : __DIR__"yaodian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

