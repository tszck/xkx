// Room: /d/henshan/mojingtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "磨鏡臺");
        set("long", @LONG
磨鏡臺位於燕子巖下，與半山亭一溝相鄰。臺前峯迴路轉，臺旁古
松蒼翠，環境清幽。相傳南宗禪宗懷讓在此宣揚 "頓悟法門" ，坐枱高
僧鬥法，懷讓磨鏡，智服北宗道一，此臺因而傳名。 "磨鏡臺之幽" 是
衡山大四絕之一。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu8",
           "westup"     : __DIR__"shanlu7",
           "northup"    : __DIR__"shanlu6",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
