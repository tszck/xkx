// Room: /d/lingxiao/andao.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","暗道");
	set("long",@LONG 
這是一條凌霄城的暗道，看來是凌霄城裏什麼人出入的祕密通道。
在牆上插着的幾根火把所散發出的光芒下，可以看到地下有一本書，不
知道是哪個粗心鬼掉在這裏的。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"out"       : __DIR__"muwu",
		"northdown" : __DIR__"didi",
	]));
	set("objects", ([
		BOOK_DIR+"sword_book3" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}

