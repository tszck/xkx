// Room: /d/wudujiao/cun8.c

inherit ROOM;

void create()
{
        set("short", "村東口");
        set("long", @LONG
這裏是小村的東頭。因為暴雨剛過，地上一片泥濘，路非常不好走。順
着這條路一直向東走一兩個時辰就可到青石坪了，那裏是這附近最大的鎮子。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"cun7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}