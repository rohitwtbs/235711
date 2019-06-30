/* eslint-disable */

<template>
  <div id="jsonViewer">
       <table class="table">
      <thead>
          <tr v-for="(column, index) in payload" :key="index" :ref="`myRow${column}`">
            <th> {{index}}</th>
            <th v-if="parse"> {{column}}</th>
          </tr>
              
         
      </thead>
       </table>
  </div>
</template>

<script>
// import Vue from 'vue';
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data() {
    return {
    payload : 
      {
    "destination_addresses" : [ 
        "Washington, DC, USA"
    ],
    "origin_addresses" : [ 
        "New York, NY, USA"
    ],
    "status" : "OK"
}
    
    };
  },
  computed : {
    parse : function() {
      console.log(this.$refs);
      console.log('rohit');
      console.log(this.$key);
      console.log(this.payload.status);
      //if (typeof(obj) === Object)
      return true;
      //else
      // return false;
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #dddddd;
}
</style>
