// /kaifeng/fenjiao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "糞窖");
	set("long", @LONG
一股臭味撲鼻而來，一堆金頭蒼蠅圍着個小池子不斷打轉，這是個
方便僧人用來澆灌菜地的小糞池子，自然是比較不好聞你還是趕快走開
些吧，不小心會掉下去的。
LONG);
	set("objects", ([
		__DIR__"npc/popi" : 1,
		__DIR__"npc/wulai" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"maofang",
		"north" : __DIR__"kongdi",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
