// Room: /d/wudujiao/xiaodian.c

inherit ROOM;

void create()
{
        set("short", "路邊小店");
        set("long", @LONG
這是一家山野小店，供應一些食物和時鮮山貨。這裏行人稀
少，大概一天也沒幾個人路過這裏，老闆娘把店開在這裏恐怕是
要賠了。店內進是一間客房，行人累了可以進去休息。
LONG
        );

        set("exits", ([
                "east" : __DIR__"shanlu1",
                "west" : __DIR__"neijin",
        ]));
        set("objects", ([
                __DIR__"npc/sun": 1,
        ]));

	set("coor/x", -45010);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}