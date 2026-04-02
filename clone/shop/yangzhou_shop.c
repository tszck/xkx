// /clone/shop/yangzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "月明軒");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/city/majiu",
        ]));
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
這裏是揚州城裏最著名的店鋪，整個鋪面裝修得相當精美雅緻，顯
出十里揚州繁華大方的氣派。不過店裏的貨櫃上卻空無一物，看樣子已
經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
這裏是揚州城裏最熱鬧的店鋪，鋪里人來人往，川流不息。鋪面裝
修得精美雅緻，顯出十里揚州繁華大方的氣派。店鋪裏的夥計正招呼着
客人，忙得滿頭大汗。
LONG);
        return;
}

