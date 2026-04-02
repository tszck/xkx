// ROOM lianfushi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "斧頭林");
	set("long", @LONG
這裏是玄兵古洞的打造斧頭的地方。處在密密層層的叢林中。林中
有一塊小小空地，擺着一個很簡陋的鐵爐和風箱，旁邊一個虯鬚大漢手
拉風箱，雙目全神貫注盯着爐中蘭色的火苗。
LONG );
	set("exits", ([
		"south" : "/d/heizhao/shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/shifu" :1,
	]));
	set("coor/x", -4000);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
