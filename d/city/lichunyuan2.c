// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "麗春樓");
        set("long", @LONG
你站在麗春院二樓。滿耳的淫聲穢響不絕如縷。佈置的絕對精緻的
牀上地下，突然對你產生莫名的誘惑和衝動。
    幾個可憐兮兮的千嬌百媚在點手兒招你，你想到她們可能就是昔日
江湖中的眼高於頂，頓時大為開心。
LONG);
        set("exits", ([
            "down" : __DIR__"lichunyuan",
        ]));
        set("objects", ([
            __DIR__"npc/guigong" : 1,
//            __DIR__"usa/albright" : 1,
        ]));
	set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        set("piao_room", "1");
	set("coor/x", 30);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
    if (me->query_condition("prostitute"))
      return notify_fail("龜公一把抱住你：看你往哪裏逃！\n");
    return ::valid_leave(me,dir);
}