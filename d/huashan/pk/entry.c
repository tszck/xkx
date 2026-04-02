#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "紫竹林入口");
	set("long", @LONG
這裏是懸崖邊上的一小塊空地，邊上有一片茂密的竹林，
裏面黑乎乎的，也不知道通往哪裏。
LONG);
	       
        set("no_fight", 1);
        set("no_quit",1);
        set("no_sleep_room",1);
	setup();
}
