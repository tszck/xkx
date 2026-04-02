// Room: /yangzhou/tianningshuju.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","天寧書局");
	set("long",@LONG
這裏專賣市坊中各種字畫和書籍刻本，其中還有不少是難得一見的
珍本，但由於老闆不善經營，加上地方過於偏僻，所以每天買書，看書
的人沒有多少，店內光線有些不足，只有老闆辛友清一人無精打採地守
着，四周書架(shelf) 亂七八糟堆着一些卷軸，線訂本，給人一種雜亂
無章的感覺。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"tianningxiang",
	]));
	set("objects", ([
		__DIR__"npc/bookboss" : 1,
	]));
	set("item_desc", ([
		"shelf"  : "書架上堆滿了書，有些已經翻得破破爛爛。\n",
	]));
	set("coor/x", 30);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}