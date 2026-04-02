// Room: /u/cuer/emei/yhrkou.c
inherit ROOM;
void create()
{
        set("short", "雲海入口");
        set("long", @LONG
這裏就是峨嵋著名的雲海了，放眼望去，漫山遍野都
是雲霧，根本就弄不清自己身在何出。在霧中隱隱約約有
一條小道通向前方，還是回去吧。
LONG
        );
        set("exits", ([
            "enter" : __DIR__"hcahoudian",
            "north" : __DIR__"yunhai1",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1190);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}