/* Many algorithms can be decomposed into higher and loewr level parts
 * Making tea can be decomposed into 
 *  The proess of making a hot beverage(boil water ,pour into cup); and
 *  Tea-Specific htings(put teabag into water)
 *
 *  Thei high-lvevel algorithm can then be reused for making coffee or hot chocolate
 *      Supported by beverage-specifc strategy
 *
 *  Enaables the exact behavior of a system to be selected either at run-time(dynamci) or compile-time(static)
 */


/* strategy for printing list of items 
 */



enum class OutputFormat
{
    markdown, 
    html
};

struct ListStrategy
{
    virtual void start(ostringstream & oss){}
    virtual void end(ostringstream & oss) {}
    virtual void add_list_item( ostringstream & oss, const string & item) =0;
};

// we want to make the text processor componetnt 

struct TextProcessor
{
    void set_output_format( const OutputFormat & format)
    {
        switch(format)
        {
            case OutputFormt::markdown:
                list_strategy = make_unique<MarkdownListStrategy>();
                break;
            case OutputFormat::html:break;
                                    list_st

    // dynamic and static approach 
    private:
        ostringstream oss;
        unique_ptr<ListStrategy> list_strategy;

//* hdajks
// * hdjask
// <ul>
//  <li> dasjhdkh </li>
// </ul>
//
// we have three different items  
