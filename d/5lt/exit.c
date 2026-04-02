// Room: /d/5lt/exit.c

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
這裏是揚州郊外，雖然遠離縣城，卻沒有什麼山賊草寇在附近出沒。
西面是一個小村莊，村民們過着日出而作，日落而息的寧靜生活，儼然
世外桃源怡然自得的樣子。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"qsroad",
		"east" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
        ]) );
//	set("no_clean_up", 0);
        set("outdoors", "5lt" );
	set("coor/x", -110);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}