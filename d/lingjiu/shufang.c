//ROOM: shufang.c

inherit ROOM;

void create()
{
	set("short", "沁芳軒");
	set("long",@LONG
這是『靈鷲宮』的書房，靠牆擺放着一溜書架，上面整齊地排列着
各種書籍。屋子正中是一張墨色小几，几上的香爐冒出縷縷輕煙，幾前
有個蒲團可供你盤坐而讀，除此之外別無他物。你不由低呼：“好一個
雅靜所在！”
LONG );
	set("exits", ([
		"west" : __DIR__"men2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50990);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}