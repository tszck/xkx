// Room: /d/wudujiao/langwo.c

inherit ROOM;

void create()
{
        set("short", "狼窩");
        set("long", @LONG
這裏是密林中的一個大樹洞，裏面腥味撲鼻，隨處都是喫剩的
獸骨。幾隻瘦得皮包骨頭的餓狼正抖擻精神，似乎要出去覓食了。
LONG
        );

        set("exits", ([
                "out" : __DIR__"milin4",
        ]));
        set("objects", ([
                __DIR__"npc/wolf1": 2,
                __DIR__"npc/wolf2": 1,
        ]));

	set("coor/x", -45000);
	set("coor/y", -80100);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}