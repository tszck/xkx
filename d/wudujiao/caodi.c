// Room: /d/wudujiao/caodi.c

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
這裏是林中的一片空地，四周被參天的古松環抱着，當中是一片綠
油油的草地。草地中央地上有一個拳頭大小的小洞，旁邊丈許方圓寸草
不生，露出紅褐色的土壤。四周一片寂靜，草地上陽光明媚，但你的心
情卻一也不輕鬆，這裏該不會有什麼危險吧？
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"sl7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}