// Room: qingyang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "青羊宮");
	set("long", @LONG
青羊宮是天下第一大道觀。觀中林木婆娑，冠蓋亭亭。觀中道士匆
匆來去，沒人得空理你，更沒人接待你。你覺得到一種寬鬆的失落。
LONG );
	set("exits", ([
		"southeast" : __DIR__"nanjie2",
	]));
	set("objects", ([
		__DIR__"npc/dao-ren" : 1,
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
