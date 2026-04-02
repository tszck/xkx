// Room: /yangzhou/shiliji3.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
這是一條寬闊的青石街道，向南北兩頭延伸。北邊是北城門通向城
外。南邊顯得很繁忙。東邊是一座兩層的樓閣，掛着“太白遺風”的招
簾，門額上懸掛一方橫匾，“醉仙樓”三字擦得閃閃發亮，乃是蘇學士
的手筆。陣陣酒肉香讓你垂涎欲滴。西邊是一座樣式古樸的廟宇，香火
繚繞，那就是天下學武之人所共同敬仰的武廟了。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"wumiao",
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"shilijie4",
		"north" : __DIR__"shilijie2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/ma" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
