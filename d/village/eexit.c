// Room: /d/village/nwexit.c

inherit ROOM;

void create()
{
	set("short", "東村口");
	set("long", @LONG
這裏是華山腳下，雖然遠離縣城，卻沒有什麼山賊草寇在附近出沒。
往東就是上山的路了。西邊是一個小村莊，村子裏人家並不多，村民們過
着日出而作，日落而息的寧靜生活。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"eroad1",
		"east" : "/d/huashan/path1",
	]));
        set("objects", ([
            __DIR__"npc/boy": 1
        ]) );

//        set("no_clean_up", 0);
        set("outdoors", "village" );
	set("coor/x", -930);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}