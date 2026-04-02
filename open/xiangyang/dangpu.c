// Room: /d/xiangyang/dangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "當鋪");
	set("long", @LONG
這是家遠近聞名的當鋪，三開間的門面，一塊寫着『邱航
當鋪』四個金字的黑匾，足足七尺高的紫檀木的櫃枱被磨得光
可照人，你一進去就有一種壓抑和悲悵的感覺，櫃枱後的老闆
邱航頭也不抬的只顧撥拉着算盤，櫃枱上方掛着一塊花木牌子
(paizi) 。據街坊們説鐵面當鋪給的價還不算最壞，並且從不
問貨的來處，除了活人什麼都收，所以生意很不錯。
LONG );
	set("item_desc", ([
		"paizi" : "
你情我願，概不賒欠。\n",
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"north" : __DIR__"westjie1",
	]));
	set("objects", ([
		__DIR__"npc/qiuhang" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}