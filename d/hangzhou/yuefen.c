// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "嶽墳");
        set("long", @LONG
墓道兩旁有石虎，石羊，石馬和三對翁仲。正中古柏交柯，便是嶽飛的
墳墓。墓碑刻着“宋嶽鄂王墓”。嶽王墓的左面，便是嶽飛之子嶽雲的墓，
墓碑上刻着“宋繼忠侯嶽雲之墓”。在嶽墳前面兩邊四個鐵像(statue)。東
首牆上有四個大字(word)。
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"北邊兩個是秦檜和他的妻子王氏；南邊兩個是同謀殺害嶽飛的奸臣，
張俊和万俟屑。四個鐵像都反剪着手，向嶽墓跪着。\n",
            "word"   :
"牆上有“精忠報國”四個大字。這是岳母當年訓子時在嶽飛背上刻的字。\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
