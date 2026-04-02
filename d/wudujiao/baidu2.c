// Room: /d/wudujiao/baidu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/baidu1",
        __DIR__"npc/baidu2",
        __DIR__"npc/baidu3",
        __DIR__"npc/baidu4",
        __DIR__"npc/baidu5",

});

void create()
{
        set("short", "百毒窟");
        set("long", @LONG
這裏是一個天然形成的石洞，裏面深邃廣大。洞頂懸掛着許多
鐘乳石，不時傳來幾聲滴答的水聲。走在洞裏，洞內陰暗潮溼，身
旁忽然傳來一陣“噝噝”的聲音。
LONG
        );

        set("exits", ([
                "north" : __DIR__"baidu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

