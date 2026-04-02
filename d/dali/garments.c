//Room: /d/dali/garments.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","薛記成衣鋪");
	set("long",@LONG
這是一家老字號的估衣莊，裏面擺滿了各式各樣的衣物。
綢、絹、絲、布、皮襖、大紅鬥蓬、蔥黃綾子棉裙、水綠色
棉襖，秋香色團花。。。不一而足。
LONG);
	set("objects", ([
	   __DIR__"npc/xueboss": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"taiheeast",
	]));
	set("coor/x", -39990);
	set("coor/y", -71000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}