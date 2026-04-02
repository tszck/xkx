// Room: /d/wudujiao/wandu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/wandu1",
        __DIR__"npc/wandu2",
        __DIR__"npc/wandu3",
        __DIR__"npc/wandu4",
        __DIR__"npc/wandu5",
});

void create()
{
        set("short", "萬毒窟");
        set("long", @LONG
這裏是一個天然形成的石洞，裏面深邃廣大。洞頂懸掛着許多
鐘乳石，不時傳來幾聲滴答的水聲。走在洞中，洞內陰暗潮濕，身
旁忽然傳來一陣“噝噝”的聲音。洞內似乎還有個小一點的支洞。
LONG
        );

        set("exits", ([
              "south" : __DIR__"wandu3",
              "north" : __DIR__"wandu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

