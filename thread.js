class Foo{
    constructor(){
        this.runned ={
            first:false,
            second:false,
            third:false,
        }
        this.asked = {
            first:false,
            second:false,
            third:false,
        }
        this.paramFunc = {
            first : () => {},
            second : () => {},
            third : () => {}
        }
    }

    first(print){
        this.runned.first = true;
        this.asked.first = true;
        print();
        if(this.asked.second){
            this.second(this.paramFunc.second);
        }
    }
    second(print){
        this.asked.second = true;
        if(this.runned.first){
            print();
            this.runned.second = true;
            if(this.asked.third){
                this.third(this.paramFunc.third);
            }
        } else{
            this.paramFunc.second = print;
        }
    }
    third(print){
        this.asked.third = true;
        if(this.runned.second){
            print();
            this.runned.third = true;
        } else{
            this.paramFunc.third = print;
        }
    }
}

(() =>{
    const foo = new Foo();
    foo.second(() => console.log("Second"));
    foo.third(() => console.log("Third"));
    foo.first(() => console.log("One"));
})();