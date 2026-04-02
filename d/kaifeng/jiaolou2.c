// /kaifeng/jiaolou2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "東角樓");
	set("long", @LONG
東角樓是平時駐兵來守望的地方。一般只在樓的頂端掛了個氣死風
燈。日夜有人值守。從此向西下是朱雀門，東下是東大街，你眺目遠處。
湖泊，樓閣，真是大好江山。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"zhuque",
		"eastdown" : __DIR__"eroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
