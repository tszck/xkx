// Room: /d/wudujiao/qiandu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/qiandu1",
        __DIR__"npc/qiandu2",
        __DIR__"npc/qiandu3",
        __DIR__"npc/qiandu4",
        __DIR__"npc/qiandu5",
});

void create()
{
        set("short", "千毒窟");
        set("long", @LONG
這裏是一個天然形成的石洞，裏面深邃廣大。洞頂懸掛着許多
鐘乳石，不時傳來幾聲滴答的水聲。走在洞中，洞內陰暗潮濕，身
旁忽然傳來一陣“噝噝”的聲音。
LONG
        );

        set("exits", ([
              "south" : __DIR__"qiandu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

