// Room: /d/xiangyang/bingying3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "兵營");
	set("long", @LONG
這裏是兵營，密密麻麻到處都是官兵，有的在武將的指揮
下列隊操練，有的獨自在練功，有的坐着、躺着正在休息。南
牆下坐着主帥，不動聲色地尋視着四周。看到你進來，他們全
都向你瞪大眼睛盯着你。
LONG );
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"south" : __DIR__"westjie3",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -540);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

