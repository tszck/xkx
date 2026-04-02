// Room: /beijing/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "錢莊");
	set("long", @LONG
這是一家老字號的錢莊，已有幾百年的歷史，在全國各地都有分店。
它發行的銀票信譽非常好，通行全國。不管你走到哪裏，在任何一個本
莊分店都可以任意存取。牆上掛着一個牌子(paizi)。
LONG );
	set("item_desc", ([
        "paizi" : "\n本莊有利息，至少百分之一。\n
      存錢        deposit或者cun\n
      取錢        withdraw或者qu\n
      錢幣兌換    convert或者duihuan\n
      查帳        check或者chazhang\n",
	]));
	set("exits", ([
		"west" : __DIR__"wangfu1",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("objects", ([
		CLASS_D("yunlong")+"/qianlaoben" : 1
	]));

	set("coor/x", -170);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
