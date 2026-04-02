inherit ROOM;
void create()
{
        set("short", "山洞");
        set("long", @LONG
這是一個藏在瀑布背後的山洞，藉着瀑布外的微光可
以看到山洞的大概輪廓。這是一個很大的天然洞穴，空氣
中充滿着很濃的硫磺味道，往東還有一個內洞。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "out" : __DIR__"pubu",
            "east" : __DIR__"shdong2",
        ]));
	set("coor/x", -6200);
	set("coor/y", -1150);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}