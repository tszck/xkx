// shidong10.c 石洞

inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG
這是一個石室，隱約可以感覺到四周是冰冷而堅硬的石壁，石
洞內乾乾淨淨，一塵不染。
LONG );
        set("exits", ([
               "east" : __DIR__"shidong9",
               "out"  : __DIR__"dating",
        ]));
        set("objects", ([
               WEAPON_DIR"treasure/baihong-jian" : 1,
        ]));
	set("coor/x", -3110);
	set("coor/y", -22070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
            tell_object(me,"你走出了石洞，神祕地出現在大廳之中。\n");
        return ::valid_leave(me,dir);
}
