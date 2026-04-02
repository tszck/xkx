// 店鋪繼承
// shop.c

inherit ROOM;
inherit F_SAVE;

#include <ansi.h>

string long()
{
	switch (query("shop_type"))
        {
// 店鋪關閉時的描述
	        case 0  : return query("long");
// 店鋪開放時的描述
	        default : 
// 默認描述
			if (! stringp(query("open_long")))
				return @LONG
這裏是一間裝飾得非常豪華的店鋪，鋪面寬敞明亮，櫃子
上擺滿了各式各樣、琳琅滿目的貨物。此時一位夥計正忙裏忙
外地招呼着客人。
LONG;
// 特殊描述
			else return query("open_long");
        }
}

void setup()
{
        object waiter, ob;
        string *props, prop;
	int i;
        mapping m;

        ::setup();
        if (! restore())
                save();

        ob = this_object();
        waiter = present("huo ji", ob);

        if (waiter)
        {
                if (! mapp(m = ob->query("waiter"))) return;
                props = keys(m);

                if (! props) return;
/* 替代foreach */
		for (i = 0; i < sizeof(props); i++)
                {
			if(prop == props[i])
			{
	                        if (prop == "name")
					waiter->set_name(ob->query("waiter/" + prop), waiter->parse_command_id_list());
				waiter->set(prop, ob->query("waiter/" + prop));
			}
                }
/*
                foreach (prop in props)
                {
                        if (prop == "name")
                                waiter->set_name(ob->query("waiter/" + prop),
                                                 waiter->parse_command_id_list());
                        waiter->set(prop, ob->query("waiter/" + prop));
                }
*/
        }
}

string query_save_file()
{
        string id;

        sscanf(base_name(this_object()), "/%*s/%*s/%s_shop", id);

        if (! stringp(id)) return 0;

        return sprintf(DATA_DIR "/shop/%s", id);
}

int save()
{
        string file;

        if (stringp(file = this_object()->query_save_file()))
        {
                assure_file(file + __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if (stringp(file = this_object()->query_save_file()) &&
            file_size(file + __SAVE_EXTENSION__) > 0)
                return restore_object(file);

        return 0;
}
