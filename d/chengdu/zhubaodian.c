// Room: /d/chengdu/zhubaodian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "珠寶店");
        set("long", @LONG
這裏就是全國聞名的“謝記”珠寶店。謝家做珠寶這一行已經有了
上百年的歷史，以其選材上乘，製作精巧，花樣繁多而為達官貴族所青
睞，因為如果身上佩帶有“謝記”珠寶就是一種身份的象徵。門口掛的
招牌雖然有些舊了，卻顯示出它歷史的悠久。
LONG	);
        set("exits", ([                
                "east" : __DIR__"beijie2",                
        ]));
        set("objects", ([
                __DIR__"npc/yunyan" : 1,
                __DIR__"npc/huoji" : 1,
        ]));
        set("coor/x", -8060);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 
