// Room: /d/5lt/shijie.c

inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
你走在青石板鋪成的石階上。這些日子雨下個不停，石階上生成點
點苔蘚，路面有些溼滑。淡淡煙雨中，你可以望見石階羊腸似的一路延
伸上去，就像是一條怪蛇彎曲着向上爬行，直入青雲。
LONG);
        set("exits", ([ /* sizeof() == 1 */
            "northdown" : __DIR__"wroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -180);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}