pipeline {
  agent any
  stages {
    stage('Step 01') {
      steps {
        echo 'Batata'
        input(message: 'Posso aprovar?', id: 'sim', ok: 'Deploy')
        echo 'Foi'
      }
    }
    stage('Gogogogo') {
      steps {
        echo 'fim'
      }
    }
  }
}