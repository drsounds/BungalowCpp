#ifndef HTML_H
#define HTML_H

namespace spider {
class HTML
{

    public:
        string *innerText;
        string *uri;
        int position;

        HTML(string *html);
        virtual ~HTML();
    protected:
    private:
};
}

#endif // HTML_H
