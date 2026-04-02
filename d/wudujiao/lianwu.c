// Room: /d/wudujiao/lianwu.c

inherit ROOM;

void create()
{
        set("short", "練武場");
        set("long", @LONG
這裏是院內的練武場，黃土場地上擺放着一些練功的石鎖，沙袋。
一個小頭目正在指導弟子練武。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east"  : __DIR__"dating",
                "west"  : __DIR__"damen",
                "south" : __DIR__"nanyuan",
                "north" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/jiaotou": 1,
        ]));

	set("coor/x", -44920);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}