// Room: /yangzhou/shiliji2.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
十里長街乃是城裏的繁華地段，一到晚上，一派燈紅酒綠，尤為熱
鬧。笑聲、歌聲、琴聲、簫聲，匯成一片送入了你的耳朵，你不禁心猿
意馬，很想就此停步享受一番。南邊是一個熱鬧的廣場。西邊是一家店
鋪，牆上寫着一個大大的“當”字，仔細傾聽，可以聽到壓低的討價還
價的聲音。東邊則是一片喧囂，夾雜着“一五一十”的數錢聲，原來那
是方圓千里之內最大的一家賭場。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"dangpu",
		"east"  : __DIR__"duchang",
		"south" : __DIR__"shilijie3",
		"north" : __DIR__"shilijie1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/bao" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}