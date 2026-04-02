// Room: /d/heimuya/dating3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "青龍堂");
	set("long", @LONG
這是『日月神教』下第三大堂：青龍堂的大廳，十分氣派，又或有
一條青龍時隱時現。堂樑上有一塊匾(bian)。
LONG    );
	set("exits", ([
		"south"     : __DIR__"chlang1",
		"northdown" : __DIR__"guang",
	]));
	set("item_desc", ([
		"bian": "上面寫到：長虹貫日，青龍飛天。千秋萬載，一統江湖 。\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}