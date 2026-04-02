//Room: /d/huashan/shop.c

inherit ROOM;

void create()
{
	set("short", "小喫店");
	set("long", @LONG
這裏是石樑邊的一間小喫店，賣些簡單的飲食，專門賺那些遊客的
錢。
LONG );
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
//        set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -870);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}
