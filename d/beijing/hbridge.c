inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "筒子橋");
        set("long", @LONG
這是一座破舊的石橋，橋下是護城河緩緩的流水。水看上去很清，
這裏是進皇宮後門的必經之路。
LONG);
        set("outdoors", "beijing");
        set("exits", ([
                "north" : __DIR__"di_anmen",
                "south" : "/d/huanggong/jingshan",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -250);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
