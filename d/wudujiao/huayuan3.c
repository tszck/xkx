// Room: /d/wudujiao/huayuan3.c

inherit ROOM;

void create()
{
        set("short", "花園");
        set("long", @LONG
這裏是個花園，一年四季都生長着各種奇異的花草，在陽光下發出七彩
妖豔的光輝。花園裏一片沉寂，竟看不到一隻蜜蜂或蝴蝶飛舞。旁邊有一座
小亭子。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"huating3",
                "south" : __DIR__"huayuan1",
        ]));

	set("coor/x", -44900);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}