//      hubian2.c 湖邊小路

inherit ROOM;

void create()
{
        set("short","湖邊小路");
        set("long",@LONG
這是聖湖邊的小路。長草越徑，蟲鳴陣陣，偶爾有白色水禽掠湖點
水，激起圈圈漣漪。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "northeast" : __DIR__"hubian3",
                "west" : __DIR__"hubian1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
