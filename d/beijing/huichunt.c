// Room: /beijing/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "回春堂藥店");
	set("long", @LONG
這是一家藥鋪，一股濃濃的藥味讓你幾欲窒息，那是從藥櫃上的
幾百個小抽屜裏散發出來的。一位老者在櫃檯後站着。櫃檯上貼着一
張發黃的廣告(guanggao)。櫃檯後面往西是一間內室(neishi)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下藥品：
金創藥：\t五十兩白銀
其他神藥與老闆面議。\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji2" : 1,
		CLASS_D("yunlong")+"/xutianchuan" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xichang1",
                "west" : __DIR__"neishi",   
	]));
//	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
