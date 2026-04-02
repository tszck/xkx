// Room: /d/wudujiao/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "山邊小路");
        set("long", @LONG
一條蜿蜒的小路延着山腳向前延伸，兩旁是濃密的樹林，腳
下是崎嶇不平的山路，前面就是可怕的黑森林了。旁邊似乎有一
家山野小店，路邊有一座石碑(bei)。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"milin1",
                "west" : __DIR__"xiaodian",
                "north" : __DIR__"road3",
        ]));

        set("item_desc",([
            "bei":"           前方黑森林山高林密，百里之內不見人煙，\n
           有虎狼出沒其中，行人請三思而後行！\n",
        ]));

	set("coor/x", -45000);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}